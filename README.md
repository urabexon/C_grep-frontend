# C_grep-frontend

## **Summary**
`onigrep` と `gre2p` は、正規表現を用いてファイルの内容を検索するコマンドラインツールです。  
以下の2種類の正規表現ライブラリを用いて構築されています：
- **onigrep**: [Oniguruma](https://github.com/kkos/oniguruma) を使用。
- **gre2p**: [RE2](https://github.com/google/re2) を使用。

これらは、特定の文字列パターンを効率的に検索するための簡易版 `grep` として設計されており、大量のテキストデータを高速に処理できます。

---

## **Features**
- **onigrep**:
  - 複雑な正規表現や Unicode 対応が必要な場合に適しています。
  - Oniguruma ライブラリを活用し、柔軟な正規表現処理を実現。
- **gre2p**:
  - Google 製の高速正規表現ライブラリ RE2 を利用。
  - バックトラックのない設計により、安定したパフォーマンスを提供。

---

## **Function**
- 任意の正規表現パターンをファイル内で検索。
- 一致した行の出力または一致した行数のカウント。
- ファイルから正規表現を読み込む機能。

---

## **Install**
### Required environment.
- **Linux または macOS**（Windows 環境では `mmap` の制約があります）。
- 必須ライブラリ：
  - [Oniguruma](https://github.com/kkos/oniguruma)
  - [RE2](https://github.com/google/re2)

### Installing dependent libraries
#### Oniguruma
Ubuntu/Debian:
```bash
sudo apt-get install libonig-dev
```

CentOS/Fedora:
```bash
sudo yum install oniguruma-devel
```

#### RE2
Ubuntu/Debian:
```bash
sudo apt-get install libre2-dev
```

CentOS/Fedora:
```bash
sudo yum install re2-devel
```

### Build
1. プログラムのディレクトリに移動します。
   ```bash
   cd <プログラムのディレクトリ>
   ```

2. `make` コマンドを実行してビルドします。
   ```bash
   make
   ```

3. 以下の2つの実行ファイルが生成されます：
   - `onigrep`
   - `gre2p`

4. クリーンアップ（生成物の削除）:
   ```bash
   make clean
   ```

---

## **Usage**

### Treatment
```bash
./onigrep <正規表現> <検索対象のファイル>
./gre2p <正規表現> <検索対象のファイル>
```

### Option
- **`-c`**: 一致する行数をカウントします。
- **`-f <ファイル>`**: 正規表現を指定したファイルから読み込みます。

### Example
1. **正規表現で検索**:
   ```bash
   ./onigrep "pattern" example.txt
   ./gre2p "pattern" example.txt
   ```

2. **一致した行数のカウント**:
   ```bash
   ./onigrep -c "pattern" example.txt
   ./gre2p -c "pattern" example.txt
   ```

3. **ファイルから正規表現を読み込む**:
   ```bash
   ./onigrep -f regex.txt example.txt
   ./gre2p -f regex.txt example.txt
   ```

---

## **How it works inside**
### 1. **onigrep**
- ファイルを `mmap` でメモリにマッピング。
- [Oniguruma](https://github.com/kkos/oniguruma) を用いて正規表現をコンパイル。
- ファイル全体をスキャンし、マッチした部分を出力またはカウント。

### 2. **gre2p**
- ファイルを `mmap` でメモリにマッピング。
- [RE2](https://github.com/google/re2) を用いて正規表現を構築。
- 長い行を分割しながらスキャンし、マッチした部分を出力またはカウント。

---

## **Notes.*
- 大きなファイルを扱う場合、メモリ使用量が増えるため十分なリソースを確保してください。
- Unicode 対応が必要な場合は **onigrep** を使用してください。
- 非常に長い行がある場合、**gre2p** の処理に制約が生じる可能性があります。