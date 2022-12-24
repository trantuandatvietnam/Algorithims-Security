const prompt = require("prompt-sync")();
function sangEratosthenes(n) {
  let check = new Array(n + 1).fill(true);
  for (let i = 2; i <= n; i++) {
    if (check[i] == true) {
      for (let j = 2 * i; j <= n; j += i) {
        check[j] = false;
      }
    }
  }
  let result = [];
  for (let i = 2; i <= n; i++) {
    if (check[i]) {
      result.push(i);
      1;
    }
  }
  return result;
}

function subArr(arr, k, start, currlen, B, n) {
  if (currlen === k) {
    let a = [];
    for (let i = 0; i < arr.length; i++) {
      if (B[i] === true) {
        a.push(arr[i]);
      }
    }
    if (sum(a) === n) {
      console.log(a);
    }
    return;
  }
  if (start === arr.length) {
    return;
  }
  B[start] = true;
  subArr(arr, k, start + 1, currlen + 1, B, n);

  B[start] = false;
  subArr(arr, k, start + 1, currlen, B, n);
}

function sum(arr) {
  return arr.reduce((a, b) => a + b, 0);
}

function run() {
  const n = prompt("Enter n: ");
  const m = prompt("Enter m: ");
  const arr = sangEratosthenes(+n);
  let B = new Array(arr.length).fill(false);
  subArr(arr, +m, 0, 0, B, +n);
}

run();
