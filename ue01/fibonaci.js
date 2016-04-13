// import
var bigInt = require("big-integer")

function fibonaciRec(callNum, maxCallNum, old, current) {
  if(callNum.greaterOrEquals(maxCallNum)) return
  var newOld = current
  var newCurrent = old.plus(current)
  console.log('Call number: ', callNum.toString(), 'fibonaci', newCurrent.toString())
  fibonaciRec(callNum.plus(1), maxCallNum, newOld, newCurrent)
}

function fibonaci(maxCallNum) {
  fibonaciRec(bigInt.zero,maxCallNum, bigInt.zero, bigInt.one)
}

try {
  var maxCallNum = bigInt(process.argv[2])
  fibonaci(maxCallNum)
} catch(e) {
  throw 'Input error 0 ' + process.argv[2]
}
