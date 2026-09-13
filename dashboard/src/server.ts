import { WebSocketServer, WebSocket } from "ws";

const wss = new WebSocketServer({ port: 8080 });

wss.on("connection", (ws: WebSocket) => {
  console.log("New client connected!");

  ws.on("message", (message: WebSocket.RawData) => {
    console.log(`Received: ${(message as Uint8Array)[0]}`);

    ws.send(`Echo: ${message}`);
  });

  ws.on("close", () => {
    console.log("Client disconnected.");
  });

  ws.send("Welcome to the WebSocket server!");
});

console.log("WebSocket server is running on ws://localhost:8080");
