# RISCbuddy
A simple RISC-V code analysis tool for checking basic errors in RISC-V assembly code.

## Features
- [ ] Check for unreturned labels by checking for labels that are not used as jump targets
- [ ] Check for outside functions calling labels
- [ ] Checking what labels are inside functions
- [ ] Checking register saving convention
- [ ] Checking register argument conventions
- and more!

This code is based on the [CMPUT 415 GeneratorBase](https://github.com/cmput415/GeneratorBase) code.

# GeneratorBase
The base cmake setup for the generator assignment.

Author: Braedy Kuzma (braedy@ualberta.ca)  
Updated by: Deric Cheung (dacheung@ualberta.ca)

# Usage
## Building
### Linux
  1. Install git, java (only the runtime is necessary), and cmake (>= v3.0).
     - Until now, cmake has found the dependencies without issues. If you
       encounter an issue, let a TA know and we can fix it.
  1. Make a directory that you intend to build the project in and change into
     that directory.
  1. Run `cmake <path-to-Generator-Base>`.
  1. Run `make`.
  1. Done.

## Pulling in upstream changes
If there are updates to your assignment you can retrieve them using the
instructions here.
  1. Add the upstream as a remote using `git remote add upstream <clone-link>`.
  1. Fetch updates from the upstream using `git fetch upstream`
  1. Merge the updates into a local branch using
     `git merge <local branch> upstream/<upstream branch>`. Usually both
     branches are `master`.
  1. Make sure that everything builds before committing to your personal
     master! It's much easier to try again if you can make a fresh clone
     without the merge!

Once the remote has been added, future updates are simply the `fetch` and
`merge` steps.
