# Hanoi-Tower
A CLI version of the Hanoi tower game.

![Démonstration](https://github.com/lolaitu/Hanoi-Tower/releases/download/untagged-eef9d813cfec9b74169a/demo.gif)

# Requirement
You will need Linux.  

Windows is too much work (I don't want to)
<br/>
<br/>

# Instalation
<br/>

## Make from source (recommended)
<br/>

### Dependecy
You will need to have `make` and `g++`.  

For exemple with debian based distro : 
```bash
sudo apt install make g++
```
<br/>

### Install
1. Clone the repository :
```bash
git clone https://github.com/lolaitu/Hanoi-Tower.git
```
2. Navigate to the project directory:
```bash
cd Hanoi-Tower
```
3. Install the game:
```bash
make install
```
<br/>

> [!NOTE]
> Make sur that `~/.local/bin` is correctly included in your $PATH.
<br/>

If you just want to try, type :

```bash
make run
```
<br/>

## Release
<br/>

Download the latest release from the  [![Latest Release](https://img.shields.io/badge/Release-Latest-blue?logo=github)](https://github.com/lolaitu/Hanoi-Tower/releases)  page.  
> [!NOTE]
> If it wouldn't lauch maybe you didn't give it permission.
<br/>

# Uninstallation
<br/>

when in `Hanoi-Tower/` , type in :
```bash
make uninstall
```

