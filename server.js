
const express = require("express");
const bodyParser = require("body-parser");
const path = require("path");

const app = express();
const port = 3000;

// Middleware to parse form data
app.use(bodyParser.urlencoded({ extended: true }));

// Serve the HTML file
app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "index.html"));
});

// Handle form submission
app.post("/submit", (req, res) => {
  const { title, name, details } = req.body;

  console.log("Received submission:");
  console.log("Project Title:", title);
  console.log("Name:", name);
  console.log("Details:", details);

  res.send(`<h2>Thanks, ${name}! Your project "${title}" has been submitted successfully.</h2>`);
});

app.listen(port, () => {
  console.log(`Server running on http://localhost:${port}`);
});
