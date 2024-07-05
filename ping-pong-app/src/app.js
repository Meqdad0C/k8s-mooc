import express from 'express';

const app = express();
let number_of_hits = 0;


app.get('/pingpong', (req, res) => {
    res.send(`pong ${number_of_hits++}\n`);
});

export default app;