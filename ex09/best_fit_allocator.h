#include <stdlib.h>
#include <stdio.h>

// commulative malloc calls (or a single one) exceeding this amount of bytes will fail
#define TOTAL_SIZE 1024*1024

// management data to be stored per allocation block
typedef struct Block {
	size_t size; // size of the block (not including management data)
	struct Block* next; // pointer to next block
} Block;

Block* head;

void initAllocator() {

	// initial block, provides point of entrance to our list
	head = (Block*)malloc(TOTAL_SIZE);
	head->size = 0;
	head->next = head + sizeof(Block);

	// all memory is available in a single, large block
	Block* hugeBlock = head->next;
	hugeBlock->size = TOTAL_SIZE - sizeof(Block) * 2;
	hugeBlock->next = NULL;
}

void destroyAllocator() {
	free(head);
}

void* myMalloc(size_t size) {
	
	if(head == NULL) {
		fprintf(stderr, "Error, allocator is not initialized\n");
		return NULL;
	}
	
	Block* current = head->next; // current block that we examine for its size
	Block* previousOfCurrent = head; // previous block of current
	Block* best = current; // the minimally-sized block so far that fits the requirements
	Block* previousOfBest = head; // previous block of min

	// keep looking till the end...
	while(current != NULL) {
		// if block fits requirements and is smaller than the best so far
		if(current->size >= size && current->size < best->size) {
			// save pointers to best and its previous
			best = current;
			previousOfBest = previousOfCurrent;
		}
		previousOfCurrent = current;
		current = current->next;
	}

	if(best == NULL) {
		fprintf(stderr, "Error, unable to find a free block of at least %lu bytes\n", size);
		return NULL;
	}

	// if there is enough space, shrink and move free block
	if(best->size > (size + sizeof(Block))) {
		// new block located at the end of the current allocation
		Block* newBlock = best + sizeof(Block) + size;
		newBlock->size = best->size - sizeof(Block) - size;
		newBlock->next = best->next;
		// current block is shrunk to the current allocation
		best->size = size;
		// remove link to next, as it no longer makes sense
		best->next = NULL;
		// by-pass current block for future searches
		previousOfBest->next = newBlock;
	} else {
		// if space is an exact match, simply by-pass current block and remove its link to next
		previousOfBest->next = best->next;
		// remove link to next, as it no longer makes sense
		best->next = NULL;
	}


	// obtain address of actual free space of best block
	void* address = best + sizeof(Block);

	return address;
}

void tryMerge(Block* first, Block* second) {
	// check if the second block immediately follows the first one
	if((first + first->size + sizeof(Block)) == second) {
		// if so, the first block needs to cover both their memory area
		first->next = second->next;
		first->size += second->size + sizeof(Block);
	}
}

void myFree(void* address) {
	Block* blockToBeFreed = (Block*)address - sizeof(Block);

	Block* current = head;
	// search for the block that our to-be-free'd block should be inserted after
	while(current->next != NULL && current->next < blockToBeFreed) {
		current = current->next;
	}

	if(current == NULL) {
		fprintf(stderr, "Unable to find block responsible for address %p\n", address);
		exit(EXIT_FAILURE);
	}

	// re-add block to chain of free blocks
	blockToBeFreed->next = current->next;
	current->next = blockToBeFreed;

	// merge with previous block if possible
	tryMerge(current, blockToBeFreed);
	// merge with following block if possible
	tryMerge(blockToBeFreed, blockToBeFreed->next);
}
