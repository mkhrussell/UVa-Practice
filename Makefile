.PHONY: clean All

All:
	@echo "----------Building project:[ UVa-10004 - Debug ]----------"
	@cd "UVa-10004" && "$(MAKE)" -f  "UVa-10004.mk"
clean:
	@echo "----------Cleaning project:[ UVa-10004 - Debug ]----------"
	@cd "UVa-10004" && "$(MAKE)" -f  "UVa-10004.mk" clean
