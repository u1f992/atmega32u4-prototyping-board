.PHONY: release

release:
	zip -r production.zip production/* -x "production/backups/*"
