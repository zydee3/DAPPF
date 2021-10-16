
# DAPPF
I created both the work [example] environment and library itself under a single project. The work enviornment compiles down and ran as an executable. The framework is compiled to a shared library which cannot be ran as a standalone. 

# Framework
Within the framework are four main directories which pertains to each layer of the framework:
 - Layer 1: Net (Communication Layer)
 - Layer 2: Security
 - Layer 3: Data
 - Layer 4: Handlers (Processing)

Within each directory the respective directories are meta files. The meta file will hold meta data to the main files within the module. A meta file is like that of an inner class to a parent class. Using a game as an example, an example of meta data to Player class is PlayerStats which holds the stats of the player. Meta data allows us to break apart classes into smaller more organized classes in order to premote clean code and precent god classes.
