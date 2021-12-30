#----------------------------- User configuration -----------------------------

# Common settings
#------------------------

# How you're loading your module. Used to determine how to find the target module. (AsRtld/Module/Kip)
export LOAD_KIND=Module
# Program you're targetting. Used to determine where to deploy your files.
export PROGRAM_ID=0100000000010000
# Python command to use. Must be Python 3.4+.
export PYTHON=python3
# Make arguments.
export MAKE_ARGS=-j8 V=1
# JSON to use to make .npdm
export NPDM_JSON_BASE=qlaunch.json

# Settings for the network logger to use
export LOGGER_IP=192.168.1.99
export LOGGER_PORT=1984

# AsRtld settings
#------------------------

# Path to the SD card. Used to mount and deploy files on SD, likely with hekate UMS.
export MOUNT_PATH=/mnt/k

# Module settings
#------------------------

# Settings for deploying over FTP. Used by the deploy-ftp.py script.
export FTP_IP=192.168.1.136
export FTP_PORT=5000
export FTP_USERNAME=anonymous
export FTP_PASSWORD=

#-------------------------- End of user configuration --------------------------

# Setup common variables.
export BASE_DIR=$(CURDIR)
export MISC_PATH=$(BASE_DIR)/misc
export MK_PATH=$(MISC_PATH)/mk
export SCRIPTS_PATH=$(MISC_PATH)/scripts
export SPECS_PATH=$(MISC_PATH)/specs
export NPDM_JSON_PATH=$(MISC_PATH)/npdm-json

# Setup variable for .json
export NPDM_JSON=$(NPDM_JSON_PATH)/$(NPDM_JSON_BASE)

# Import target env variables.
include $(SCRIPTS_PATH)/target-common.mk

ifeq ($(LOAD_KIND),Module)
    include $(SCRIPTS_PATH)/target-module.mk
else ifeq ($(LOAD_KIND),Rtld)
    include $(SCRIPTS_PATH)/target-rtld.mk
else
$(error Invalid LOAD_KIND!)
endif

.PHONY: clean all send

# Forward defines.
export EXL_CFLAGS	:= -DEXL_LOAD_KIND=$(LOAD_KIND)	-DEXL_PROGRAM_ID=0x$(PROGRAM_ID)

export OUT_NSO := $(OUT)/$(BINARY_NAME)
export OUT_NPDM := $(OUT)/main.npdm

all:
	@$(MAKE) -f $(MK_PATH)/common.mk $(MAKE_ARGS) all DEVKITPRO=$(DEVKITPRO)
	# Clear older build.
	@rm -rf $(OUT)

	# Create out directory.
	@mkdir $(OUT)

	# Copy build into out.
	@mv $(NAME).nso $(OUT_NSO)
	@mv $(NAME).npdm $(OUT_NPDM)

	# Done.

send: all
	@$(PYTHON) $(SCRIPTS_PATH)/deploy-ftp.py

clean:
	@$(MAKE) -f $(MK_PATH)/common.mk $(MAKE_ARGS) clean