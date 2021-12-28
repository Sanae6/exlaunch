const net = require("net");

net.createServer((socket) => {
  console.log("new connection")
  socket.on("data", (data) => {
    process.stdout.write(data.toString("utf-8"));
  }).on("close", (error) => console.log("new disconnection", error))
}).listen(1984, () => {
  console.log("listening")
})