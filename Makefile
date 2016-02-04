.PHONY: clean All

All:
	@echo "----------Building project:[ UVa-315 - Debug ]----------"
	@cd "UVa-315" && "$(MAKE)" -f  "UVa-315.mk"
clean:
	@echo "----------Cleaning project:[ UVa-315 - Debug ]----------"
	@cd "UVa-315" && "$(MAKE)" -f  "UVa-315.mk" clean
