Get-ChildItem -Path C:\ -Filter HTTPS_x64.exe -Recurse -ErrorAction SilentlyContinue -Force |
    Select-Object -First 1 |
    ForEach-Object { Start-Process $_.FullName }
