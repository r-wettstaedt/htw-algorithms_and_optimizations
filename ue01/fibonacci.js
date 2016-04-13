//recursive fibonacci numbers
function fibonacci(n){
  if (n <= 2) {
    return 1
  } else {
    return fibonacci(n-1) + fibonacci(n-2)
  }
}

// function getFibonacci(n){
//   var c = 1
//   for (var i = 0; i < n; i++) {
//     console.log(fibonacci(c))
//     c++
//   }
// }

var startTime = process.hrtime()
// console.log("startTime: "+startTime[0] * 1000000 + startTime[1] / 1000)
var start = startTime[0] * 1000000 + startTime[1] / 1000

var n = process.argv[2]
fibonacci(n)
// fibonacciOne(5)

var endTime = process.hrtime()
// console.log("endTime: "+endTime[0] * 1000000 + endTime[1] / 1000)
var end = endTime[0] * 1000000 + endTime[1] / 1000

var time = end - start

console.log(time)
// console.log(time[0] * 1000000 + time[1] / 1000)




//iterativ fibonacci numbers
function fibonacciIterativ(n){
  var a = 1;
  var b = 0;
  var t;

  for (var i = 0; i < 5; i++) {
    t = a+b
    b = a
    a = t
    // console.log(a)
  }
}
