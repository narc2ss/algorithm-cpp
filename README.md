### Compoiler

```zsh
$ gcc --version
Apple clang version 13.1.6 (clang-1316.0.21.2)
Target: arm64-apple-darwin21.3.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```

### Editor

- Visual Studio Code

### Extensions

- C/C++

### Settings

```json
# settings.json

{
  "code-runner.executorMap": {
      "cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
  }
}
```

### Code Style

#### GNU

- setting.json

```json
{
  "C_Cpp.clang_format_fallbackStyle": "BasedOnStyle: Visual Studio"
}
```

- code

```cpp
if (true)
{
  cout << "Hello world;
}
```

#### K&R

- setting.json

```json
{
  "C_Cpp.clang_format_fallbackStyle": "BasedOnStyle: Google"
}
```

- code

```cpp
if (true) {
  cout << "Hello world";
}
```
