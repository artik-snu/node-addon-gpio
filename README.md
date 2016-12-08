# nodejs Addon for GPIO

- tizen 3.0
- artik 10
- nodejs 4.4.3

## Development Environment

### Ubuntu 16.04 LTS

### ARM Cross compiler

1. refer to [ARM toolchain](http://www.acmesystems.it/arm9_toolchain)
2. require to set enviroment variable

```
$ export AR=arm-linux-gnueabi-ar
$ export CC=arm-linux-gnueabi-gcc
$ export CXX=arm-linux-gnueabi-g++
$ export LINK=arm-linux-gnueabi-g++
```

### node-gyp

```
$ npm install -g node-gyp
```

## Configure & Build

more detail [addon example](https://github.com/artik-snu/node-addon-gpio/tree/master/examples/hello)

### configure

*tizen 3.0 based on ARTIK 10 requires specific nodejs version(v4.4.3)*

```
$ node-gyp --target=4.4.3 --arch=arm configure
$ vi binding.gyp # refer to 'addon example'
```

### build

```
$ node-gyp build
```

## Test

```
$ scp /path/build/hello.node name@arm-host:/path/test/addon
```

in ARM host(/path/test)

```
.
|- addon
|	`- hello.node
`- hello.js
```

```
// hello.js
var addon = require('./addon/hello');
console.log(addon.hello());
```

run like below

```
$ node hello.js # 'world'
```

## License

This project is licensed by [MIT](https://github.com/artik-snu/node-addon-gpio/blob/master/LICENSE)
