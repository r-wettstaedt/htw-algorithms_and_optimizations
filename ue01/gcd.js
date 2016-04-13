// imports
var bigInt = require("big-integer")

function extendedGCD(a, b) {
  console.log(a, b)
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

  return {
    k: d,
    uv: dUV
  }
}

var a = bigInt(93)
var b = bigInt("32942305")

console.log(extendedGCD(a,b))
