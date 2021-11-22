import { long_mult } from './modules'
import { longMult } from './utils/longMult'

const a = "98765432198765432134", b = "98765432198765432134"

const t0 = performance.now();

const cppRes = long_mult(a, b)
const t1 = performance.now();

const jsRes = longMult(a, b)
const t2 = performance.now();

console.log(`cppRes => ${cppRes} => ${t1 - t0}ms`)
console.log(` jsRes => ${jsRes} => ${t2 - t1}ms`)
