index.html: index.rst
	rst2html $^ $@
	recode u8..h -d $@

clean:
	rm index.html
