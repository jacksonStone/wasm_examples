import { evalInJS } from "./env";
// The entry file of your WebAssembly module.
export function fib(n: i32): i32 {
  var a = 0, b = 1;
  for (let i = 0; i < n; i++) {
    let t = a + b; a = b; b = t;
  }
  return b;
}

function _eval(code: string): void {
  var wrapped = '(function(){' + code + '}())';
  evalInJS(wrapped, wrapped.length);
}

export function main(): void {
  _eval("document.querySelector('body').innerText = 'Hello from AssemblyScript'");
}