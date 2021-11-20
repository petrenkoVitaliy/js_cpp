import { Add, Sub } from './types'

type Modules = {
    add: Add
    sub: Sub
}

const modules: Modules = require('../../build/Release/modules.node')

const { add, sub } = modules

export { add, sub }