DIRS = $(dir $(realpath $(firstword $(MAKEFILE_LIST))))

wiki:
	for i in $(DIRS) ; do \
		cd $(i) ; \
		ifeq (,$(wildcard ./README.md)) ; \
			pandoc -f markdown -t mediawiki README.md > md_README.txt ; \
		endif ; \
	done
