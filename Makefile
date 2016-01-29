.PHONY: clean All

All:
	@echo "----------Building project:[ UVa-352 - Debug ]----------"
	@cd "UVa-352" && "$(MAKE)" -f  "UVa-352.mk"
clean:
	@echo "----------Cleaning project:[ UVa-352 - Debug ]----------"
	@cd "UVa-352" && "$(MAKE)" -f  "UVa-352.mk" clean
