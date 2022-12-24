const n = 1000;
const m = 4;
function sangEratosthenes(n) {
    let check = new Array(n + 1).fill(true);
    // console.log(check);
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
            result.push(i);1
        }
    }
    return result;
}
const arr = sangEratosthenes(n);
console.log(arr);

function subArr(arr, k, start, currlen, B) {
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

        // console.log("--------------");
        return;
    }
    if (start === arr.length) {
        return;
    }
    B[start] = true;
    subArr(arr, k, start + 1, currlen + 1, B);

    B[start] = false;
    subArr(arr, k, start + 1, currlen, B);
}
function sum(arr) {
    return arr.reduce((a, b) => a + b, 0);
}

function run() {
    let B = new Array(arr.length).fill(false);
    subArr(arr, m, 0, 0, B);
}
run();