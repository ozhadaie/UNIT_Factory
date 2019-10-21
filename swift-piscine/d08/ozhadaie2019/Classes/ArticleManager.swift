//
//  ArticleManager.swift
//  ozhadaie2019
//
//  Created by Oleksii ZHADAIEV on 10/11/19.
//
//

import Foundation
import CoreData

//@objc(Article)
//public class Article: NSManagedObject {
//
//}

public class ArticleManager: NSObject {
    
    public var moc: NSManagedObjectContext
    
    public override init() {
        let modelName = "article"
        
        let bundle = Bundle(for: Article.self)
        guard let modelURL = bundle.url(forResource: modelName, withExtension: "momd") else {
            fatalError("Error loading model from bunlde")
        }
        
        guard let mom = NSManagedObjectModel(contentsOf: modelURL) else {
            fatalError("Unable to load data model")
        }
        
        let psc = NSPersistentStoreCoordinator(managedObjectModel: mom)
        let fm = FileManager.default
        let sn = "\(modelName).sqlite"
        
        let docURL = fm.urls(for: .documentDirectory, in: .userDomainMask).last
        let psu = docURL?.appendingPathComponent(sn)
        
        do {
            try psc.addPersistentStore(ofType:NSSQLiteStoreType, configurationName: nil, at: psu, options: nil)
        } catch {
            fatalError("Unable to load persistent store: \(error)")
        }
        moc = NSManagedObjectContext(concurrencyType: .mainQueueConcurrencyType)
        moc.persistentStoreCoordinator = psc
    }
    
    public func newArticle() -> Article {
        return NSEntityDescription.insertNewObject(forEntityName: "Article", into: self.moc) as! Article
    }
    
    public func getAllArticles() -> [Article] {
        let req = NSFetchRequest<NSFetchRequestResult>(entityName: "Article")
        
        do {
            let res = try moc.fetch(req) as! [Article]
            return res
        } catch {
            return []
        }
    }
    
    public func getArticles(withLang lang: String) -> [Article] {
        let req = NSFetchRequest<NSFetchRequestResult>(entityName: "Article")
        req.predicate = NSPredicate(format: "language == %@", lang)
        
        do {
            let res = try moc.fetch(req) as! [Article]
            return res
        }catch{
            return []
        }
    }
    
    public func getArticles(containString str: String) -> [Article]
    {
        let req = NSFetchRequest<NSFetchRequestResult>(entityName: "Article")
        req.predicate = NSPredicate(format: "title CONTAINS %@ || content CONTAINS %@", str,str)
        
        do{
            let res = try moc.fetch(req) as! [Article]
            return res
        }catch{
            return []
        }
    }
    
    public func removeArticle(article: Article)
    {
        moc.delete(article)
    }
    
    public func save()
    {
        if moc.hasChanges {
            do {
                try moc.save()
            }
            catch{
                fatalError("Failure to save content \(error)");
            }
        }
    }
}
