
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "./dynamic_list.h"
#include <emscripten.h>

int int_sqrt(int x) {
    printf("Calling printf from int_sqrt in C\n");
  return sqrt(x);
}

void run_if_browser(const char * script) {
	const char * format = "if(typeof module === 'undefined' || typeof window !== 'undefined' ){ %s }";
	int len = strlen(format) + strlen(script); 
	char full_script[len];
	sprintf(full_script, format, script);
    emscripten_run_script(full_script);
}


#ifdef __cplusplus
extern "C" {
#endif
int EMSCRIPTEN_KEEPALIVE manual_int_sqrt(int x) {
    printf("Calling printf from manual_int_sqrt in C\n");
    return sqrt(x);
}
#ifdef __cplusplus
}
#endif


int main() {
    run_if_browser("document.querySelector('body').innerText = 'Hello from C/C++'");
    char * foo = make_list(char);
    char new_entry = 'c';
    char new_entry0 = '\0';
    append(foo, new_entry);
    append(foo, new_entry);
    append(foo, new_entry);
    append(foo, new_entry0);
    printf("%s\n", foo);
    int foo_length = get_length(foo);
    printf("%d\n", foo_length);
    run_if_browser("doneCompilingWASM()");
    return 0;
}
