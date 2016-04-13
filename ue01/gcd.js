// imports
var bigInt = require("big-integer")
/*
 * Aufgabe 1
 */
function extendedGCD(a, b) {
  var startTime = process.hrtime()
  if(typeof a.value == 'undefined' || typeof b.value == 'undefined') throw 'Input type error 1'
  if(a.value < 0 || b.value < 0) throw 'Input type error 2'
  if( !(( a.isPositive() && b.isPositive() ) && ( !a.eq(0) || !b.eq(0) )) ) throw 'Input type error 3'

  var c = a
  var d = b
  var cUV = {u:bigInt(1), v:bigInt(0)}
  var dUV = {u:bigInt(0), v:bigInt(1)}

  var counter = 0

  while(c.notEquals(0)) {
    counter++
    console.log('Iteration:', counter)

    var q = bigInt(d.divide(c))

    var temp = c
    c = bigInt(d.minus(q.times(c)))
    d = temp

    var tempUV = cUV
    cUV.u = dUV.u.minus(q.times(cUV.u))
    cUV.v = dUV.v.minus(q.times(cUV.v))
    dUV = tempUV

  }
  // source: http://stackoverflow.com/questions/11725691/how-to-get-a-microtime-in-node-js
  var startTimeBig = bigInt(startTime[0] * 1000000).plus(bigInt(startTime[1]).divide(bigInt(1000)))
  var currentTimeBig = bigInt(process.hrtime()[0] * 1000000).plus(bigInt(process.hrtime()[1]).divide(1000))
  return {
    k: d,
    uv: dUV,
    time: currentTimeBig.minus(startTimeBig),
    iterations: counter
  }
}

var a = bigInt(process.argv[2])
var b = bigInt(process.argv[3])
console.log(extendedGCD(a,b))

module.exports = extendedGCD
