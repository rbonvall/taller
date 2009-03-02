index.html: index.rst
	rst2html $^ $@

clean:
	rm index.html
