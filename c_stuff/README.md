To compile, follow installation instructions for emscripten (https://emscripten.org/docs/getting_started/downloads.html)

And execute: 
`emcc main.c dynamic_list.c -o emscripten.js -s EXPORTED_FUNCTIONS='["_int_sqrt", "_main"]' -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap"]'`