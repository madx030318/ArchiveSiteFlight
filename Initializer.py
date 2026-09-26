import json
from pathlib import Path

class ArchiveBridge:
    def __init__(self):
        self.data_file = Path(
            __file__
        ).parent / "name.json"
      
    def load_data(self):


      if not self.data_file.exists():
            return []
      

        with open(
            self.data_file,
            "r",
            encoding="utf-8"
        ) as file:
