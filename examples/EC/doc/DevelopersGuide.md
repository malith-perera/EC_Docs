# Developers Guide
EC Build with CMake. Install CMake if you haven't installed it yet.
  
## Install CMake

### Windows
Open a PowerShell as administrator and run  

```
choco install cmake
```

### Linux

#### Debian 
```
sudo apt-get update
sudo apt-get install cmake
```

#### Fedora
```
sudo dnf upgrade --refresh
sudo dnf install cmake
```

### Version Number
EC version number is gathered with version and it's released age since it's first release.

\<version> . \<years> . \<months> . \<days>  

 __Version: 1 . 2 . 6 . 10__  

1 - version  
2 - years  
6 - months  
10 - days  

This mean compatible version is version 1 and the updated version is released after 2 years 6 months and 10 days after the first release. 

Version: 1.1, 1.2, 1.3, ... are stable versions which release after at least one year of development.  

Version: 1.1.2  are stable versions with newly added features after 1 year and 2 months of development.

Version: 1.1.2.30 mean this version comes with bug fixes after 2 months and 30 days since the last release.

New features only add after at least one month of development and testing circle

#### How to update the version
Go to where the software is and run
```
ec version
```
This command will zip and backup the entire software into the .ec directory in your current working space and update the [app_name]_version.h. or [lib_name]_version.h in include or src directory. 