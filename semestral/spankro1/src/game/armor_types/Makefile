build: armor_types.o

clean:
	rm -f $(wildcard *.o)
	@make -C normal_armor_type clean
	@make -C limited_immunity_armor_type clean
	@make -C physical_resistance_armor_type clean
	@make -C armor_type_factory clean
	@make -C magical_resistance_armor_type clean

normal_armor_type/normal_armor_type.o: normal_armor_type/Makefile FORCE
	@make -C normal_armor_type build

limited_immunity_armor_type/limited_immunity_armor_type.o: limited_immunity_armor_type/Makefile FORCE
	@make -C limited_immunity_armor_type build

physical_resistance_armor_type/physical_resistance_armor_type.o: physical_resistance_armor_type/Makefile FORCE
	@make -C physical_resistance_armor_type build

armor_type_factory/armor_type_factory.o: armor_type_factory/Makefile FORCE
	@make -C armor_type_factory build

magical_resistance_armor_type/magical_resistance_armor_type.o: magical_resistance_armor_type/Makefile FORCE
	@make -C magical_resistance_armor_type build

armor_types.o: limited_immunity_armor_type/limited_immunity_armor_type.o normal_armor_type/normal_armor_type.o physical_resistance_armor_type/physical_resistance_armor_type.o armor_type_factory/armor_type_factory.o magical_resistance_armor_type/magical_resistance_armor_type.o
	$(LD) -r -o $@ $^

FORCE: