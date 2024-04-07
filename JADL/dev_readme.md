## Dev setup
- Install a ubuntu 22 virtual machine (via virtual box)
- On the VM install all the required libraries
- todo: network settings
- Setup cmake on the VM to point to a linux_build folder

### Making Changes
- Make changes in visual studio on host (windows)
- Launch windows ded server
- Connect locally

### Making a linux build
- Git pull
- Run cmake
- Run cmake install

## Changes

### New CVars
sv_automaticDuelQueue: Controls whether or not players are rotated in from spectator in the duel mode
g_resetScores: When set to 1 the scores will reset on game shutdown (i.e. changing map), and this cvar will be set back to 0.

### New Commands
live: Restarts the map and resets the scores

### Support for HTTP requests
Using single header library here: https://github.com/yhirose/cpp-httplib