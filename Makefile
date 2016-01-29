.PHONY: clean All

All:
	@echo "----------Building project:[ UVa-11831 - Debug ]----------"
	@cd "UVa-11831" && "$(MAKE)" -f  "UVa-11831.mk"
clean:
	@echo "----------Cleaning project:[ UVa-11831 - Debug ]----------"
	@cd "UVa-11831" && "$(MAKE)" -f  "UVa-11831.mk" clean
