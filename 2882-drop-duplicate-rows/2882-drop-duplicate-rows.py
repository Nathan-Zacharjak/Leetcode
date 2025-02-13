import pandas as pd

def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    seenEmails = set()
    deleteIds = set()
    for id, email in enumerate(customers.email):
        id = id + 1
        print(id, email)
        if email in seenEmails:
            deleteIds.add(id)
        seenEmails.add(email)
    
    for id in deleteIds:
        customers.drop(customers[id == customers.customer_id].index, inplace = True)

    # customers = customers.drop(customers[customers.customer_id in deleteIds].index)
    return customers