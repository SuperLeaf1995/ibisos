void *malloc(size_t size)
{
    void* item = (void*) size;
    //Check if the size exceeds maximum allocatable memory
    if(size <= MAX_MEMORY_SIZE)
    {
        memory_block* current_block = (memory_block*) size;
        current_block->index = block_count;
        current_block->item = item;
        current_block->previous_block = memory_blocks[block_count - 1]->previous_block;
        memory_blocks[block_count - 1]->next_block = current_block;
        current_block->size = size;
        memory_blocks[block_count] = current_block;
        block_count++;
    }
    else
    {
        //Forget last block
        memory_blocks[block_count - 1] = NULL;
        memory_block* current_block = (memory_block*) size;
        current_block->index = block_count;
        current_block->item = item;
        current_block->previous_block = memory_blocks[block_count - 1]->previous_block;
        memory_blocks[block_count - 1]->next_block = current_block;
        current_block->size = size;
        memory_blocks[block_count] = current_block;
    }
    return item;
}