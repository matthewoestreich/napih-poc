# napih-poc
Proof of concept for native Node.js C++ addon using napi.h

# Installation

Use your favorite package manager.

```bash
npm i napih-poc
```

# Usage

```js
// cjs
const { Greeter } = require("napih-poc");
const greeter = new Greeter("cjs");
const greeting = greeter.greet();
console.log(greeting);

// esm
import { Greeter } from "napih-poc";
const greeter = new Greeter("esm");
const greeting = greeter.greet();
console.log(greeting);
```