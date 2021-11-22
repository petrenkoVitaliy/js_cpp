import { Add, Sub, Long_mult } from './types'

type Modules = {
    add: Add
    sub: Sub
    long_mult: Long_mult
}

const modules: Modules = require('../../build/Release/modules.node')

const { add, sub, long_mult } = modules

export { add, sub, long_mult }