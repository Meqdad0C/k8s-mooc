import express from 'express'
import { randomUUID } from 'node:crypto'

const timestamp = () => {
  return new Date().toISOString()
}
const uuid = () => {
  return randomUUID()
}

const app = express()
const randomID = uuid()

app.get('/', (req, res) => {
  res.send(`${timestamp()}: ${randomID}\n`)
})

const intervalPrint = (interval) => {
  setInterval(() => {
    console.log(`${timestamp()}: ${randomID}`)
  }, interval)
}
intervalPrint(5000)

export default app
