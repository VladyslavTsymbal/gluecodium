# Genium
This repository contains the Genium project.

## Building and testing
Outside of IntelliJ you can invoke the following Gradle tasks to build
the entire project:

```bash
./gradlew build
```

To run the Genium tool and generate some output based on the current set of
HelloWorld project's \*.fidl files:

```bash
./generate -input ../../projects/hello_world/libhello/fidl -output ../generated -nostdout
```

## Contributing
Work on your stuff locally, branch, commit and modify to your heart's content.
As soon as you're ready either do (assuming you have git-review installed):

```bash
git review -R
```

Or, just:

```bash
git push origin HEAD:refs/for/master
```

## Command line parameters
For information on Genium command line parameters run it with "-help":

```bash
./generate -help
```

## Caching of output files
Activation of caching feature in Genium tool is done by passing the command line option, like:

```bash
./generate -enableCaching -input <input folder> -output <output folder>
```

Running Genium tool with this option will generate a directory called *.cache* inside *output folder*
(regardless of -enableCaching option, caching gets automatically deactivated in case no valid output
directory is given). Inside this folder Genium creates the cache index files (*cpp*,*android* &
*swift*) which contain hash values of all output files written in current run by the corresponding
generator. By utilizing the hash values, Genium is able to prevent files from being overwritten
with exact same content on subsequent runs.

Additionally, files written in former Genium tool runs which are not generated in current run will be
removed from built folder together with their cache entries.

They are two situations where all cache contents get automatically deleted:

* If an error occurs while generating files (because then, consistency between hash values and file
system cannot be guaranteed).
* If Genium gets started with disabled caching, but on a folder containing cache index files
(Genium might alter file contents of existing files or remove files etc. which could lead to
inconsistent cache).

## License

Copyright (C) 2016-2018 HERE Europe B.V.

See the [LICENSE](./LICENSE) file in the root of this project for license details.
