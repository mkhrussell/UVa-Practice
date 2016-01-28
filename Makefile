.PHONY: clean All

All:
	@echo "----------Building project:[ UVa-10305 - Debug ]----------"
	@cd "UVa-10305" && "$(MAKE)" -f  "UVa-10305.mk"
clean:
	@echo "----------Cleaning project:[ UVa-10305 - Debug ]----------"
	@cd "UVa-10305" && "$(MAKE)" -f  "UVa-10305.mk" clean
