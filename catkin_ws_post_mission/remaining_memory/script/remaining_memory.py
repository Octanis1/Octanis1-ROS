import mavros
import os

def get_remaining_memory():
  memory = int(os.popen("df -h /home/ | xargs | cut -d ' ' -f 14 | sed 's/%//g'", "r").read().replace("\n",""))
  return memory


