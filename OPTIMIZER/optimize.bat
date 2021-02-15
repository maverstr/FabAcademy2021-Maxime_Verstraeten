@echo off

set size=600x
set quality=60

magick mogrify -format jpg *.png
magick mogrify -resize %size% *.jpg
magick mogrify -strip -quality %quality% *.jpg