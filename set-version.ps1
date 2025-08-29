$version = $args[0]

if (-not ($version -match '^v?(\d+)\.(\d+)\.(\d+)$')) {
    Write-Host "Version must follow format: 1.2.3 or v1.2.3"
    exit 1
}

$version = $version -replace '^v', ''
$version = $version + '.0'
Write-Host "Setting version to $version."

$cmake = Get-Content -Path ./CMakeLists.txt
$updated = $false

$cmake = $cmake | ForEach-Object {
    if ($_ -match '^\s*VERSION\s+\d+\.\d+\.\d+\.\d+') {
        $_ -replace 'VERSION\s+\d+\.\d+\.\d+\.\d+', "VERSION $version"
        $updated = $true
    } else {
        $_
    }
}

if (-not $updated) {
    Write-Host "No VERSION line found in CMakeLists.txt."
    exit 2
}

$cmake | Set-Content -Path ./CMakeLists.txt
Write-Host "Version in CMakeLists.txt updated successfully."
