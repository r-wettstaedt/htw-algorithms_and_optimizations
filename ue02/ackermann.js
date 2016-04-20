// node --stack-size=9000
// ackermann function

var bigInt = require("big-integer");

function ack(m, n){
  if ( bigInt(m.equals(0)) ) {
    var a
    return a = bigInt(n).plus(1)

  } else if ( bigInt(n.equals(0)) ) {
    var b
    return b = ack(bigInt(m).minus(1), bigInt(1))

  } else {
    var c
    return c = (ack(bigInt(m).minus(1)), ack(bigInt(m), bigInt(n).minus(1)))

  }
}

var m = bigInt(process.argv[2])
var n = bigInt(process.argv[3])
console.log(ack(m,n).value)

// ohne bigInt
// function ack(m, n){
//   if ( m === 0 ) {
//     return (n+1)
//   } else if ( n === 0 ) {
//     return (ack(m-1, 1))
//   } else {
//     return ack(m-1, ack(m, n-1))
//   }
// }
//
// var m = process.argv[2]
// var n = process.argv[3]
// console.log(ack(m,n))
