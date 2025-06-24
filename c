$bb3 = @'
$found = Get-ChildItem -Path C:\ -Filter .bb3.exe -Recurse -ErrorAction SilentlyContinue -Force | Select-Object -First 1
if ($found) {
    Start-Process $found.FullName
}
'@
iex $bb3
