@echo off

set size=800x
set quality=85

if "%1" == "" (
    %1 = ./
) 

pushd %1
magick mogrify -format jpg *.png
magick mogrify -resize %size% *.jpg
magick mogrify -strip -quality %quality% *.jpg
popd