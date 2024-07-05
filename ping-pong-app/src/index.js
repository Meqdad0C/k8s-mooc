import app from "./app.js";

const PORT = process.env.APP_PORT || 3000;

app.listen(PORT, () => {
    console.log(`Server is listening on port ${PORT}`);
});

process.on("SIGINT", () => {
    console.log("Received SIGINT - shutting down server...");
    process.exit();
});
