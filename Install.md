# Developers Guide
<hr>
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

#### How to update the version
Go to where the software is and run
```
ec version
```
This command will zip and backup the entire software into the .ec directory in your current working space and update the [app_name]_version.h. or [lib_name]_version.h in include or src directory. 