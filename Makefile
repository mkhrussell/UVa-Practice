.PHONY: clean All

All:
	@echo "----------Building project:[ UVa-573 - Debug ]----------"
	@cd "UVa-573" && "$(MAKE)" -f  "UVa-573.mk"
clean:
	@echo "----------Cleaning project:[ UVa-573 - Debug ]----------"
	@cd "UVa-573" && "$(MAKE)" -f  "UVa-573.mk" clean
