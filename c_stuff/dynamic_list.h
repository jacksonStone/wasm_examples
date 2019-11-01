#include <stdlib.h>

void * _make_list(size_t entry_size, int starting_entries);
int get_length(void * list_ptr);
void set_watermark(void * list_ptr, int watermark);
void _append(void ** list_ptr_ptr, void * entry);
#define append(list_ptr, entry) (_append((void**)&list_ptr, (void*) &(entry)))
#define make_list(type) _make_list(sizeof(type), 8)
#define make_list_with_length(type, length) _make_list(sizeof(type), length)